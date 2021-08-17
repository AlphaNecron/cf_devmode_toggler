#include <algorithm>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <string>

using namespace std;
using namespace nlohmann;

bool sendRequest(const string &value, const string email, const string &zoneId, const string apiToken) {
    json body;
    body["value"] = value;
    cpr::Response res = cpr::Patch(cpr::Url{"https://api.cloudflare.com/client/v4/zones/" + zoneId + "/settings/development_mode"},
                                   cpr::Body{body.dump()},
                                   cpr::Header{{"Content-Type", "application/json"}, {"X-Auth-Email", email}, {"X-Auth-Key", apiToken}});
    json resContent;
    try {
        resContent = json::parse(res.text);
    }
    catch (json::parse_error& e) {
        fprintf(stderr, "%s", ("Parse error at " + to_string(e.byte)).c_str());
        return false;
    }
    bool success = resContent.value("success", false);
    if (!success) {
            for (auto err : resContent.at("errors")) {
                int code = err.at("code").get<int>();
                string msg = err.at("message").get<string>();
                fprintf(stderr, "%s", (to_string(code) + ": " + msg + "\n").c_str());
            }
    } else {
        int timeRemaining = resContent["result"]["time_remaining"].get<int>();
        printf("%s", ("Time remaining: " + to_string(timeRemaining / 60) + " minute(s)").c_str());
    }
    return success;
}

string toLower(string orig) {
    string str = move(orig);
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int main(int argc, char **argv) {
    char* email = getenv("EMAIL");
    char* zoneId = getenv("ZONE_ID");
    char* apiToken = getenv("API_TOKEN");
    if (nullptr == email || nullptr == zoneId || nullptr == apiToken) {
        printf("%s", "Either EMAIL or ZONE_ID or API_TOKEN is unset!");
        return 1;
    }
    if (argc == 2) {
        string value = argv[1];
        if (toLower(value) == "on") {
            if (sendRequest("on", email, zoneId, apiToken)) return 1;
            return 0;
        } else if (toLower(value) == "off") {
            if (sendRequest("off", email, zoneId, apiToken)) return 1;
            return 0;
        }
    }
    printf("%s", "Usage: devmode-toggle on|off");
    return 1;
}

