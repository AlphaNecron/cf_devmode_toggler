# cf_devmode_toggler
A simple C++ program that lets you toggle your domain development mode with one command.

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
