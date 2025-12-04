import os, sys
import json
cd = os.chdir
configpath: str = os.path.join(os.path.dirname(os.path.abspath(__file__)), "config.json")
if sys.platform == "win32":
    configpath = configpath[0].upper() + configpath[1:]
def go(path):
    with open(configpath) as f:
        config = json.load(f)
    if path in (aliases:=config["go"]["aliases"]).keys():
        cd(aliases[path])
    else:
        cd(path)