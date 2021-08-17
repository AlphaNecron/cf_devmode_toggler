# cf_devmode_toggler
A simple C++ program that lets you toggle your Cloudflare domain development mode with one command.

### Installation guide
- Download [devmode-toggle](https://github.com/AlphaNecron/cf_devmode_toggler/releases/latest/download/devmode-toggle) to somewhere.
- Execute `chmod +x devmode-toggle`.
- Set 3 variables: `ZONE_ID`, `API_TOKEN`, `EMAIL` in your terminal using `export` command.  
  `EMAIL`: The email associated with your Cloudflare account.  
  `ZONE_ID`: You can find one in your domain's dashboard.  
  `API_TOKEN`: Navigate to [here](https://dash.cloudflare.com/profile/api-tokens) and grab Global API Key.  
- To turn off development mode, use `./devmode-toggle off`.
- To turn on development mode, use `./devmode-toggle on`.

### Building from source
```bash
git clone https://github.com/AlphaNecron/cf_devmode_toggler.git
cd cf_devmode_toggler
mkdir build
cd build
cmake ..
make
```

***
#### Fix for `error while loading shared libraries: libcpr.so.1: cannot open shared object file: No such file or directory`
```bash
git clone https://github.com/whoshuu/cpr.git --branch 1.6.2 --single-branch # replace 1.6.2 with the latest tag.
cd cpr
cmake -DCMAKE_BUILD_TYPE=Release -DCPR_BUILD_TESTS=OFF -DCPR_FORCE_USE_SYSTEM_CURL=ON .
make
mkdir -p /usr/lib
cp -r lib/libcpr* /usr/lib
mkdir -p /usr/include
cp -r include/cpr /usr/include
```
