import json

def setalias_go(real, alias):
    with open("config.json") as f:
        config:dict[str,dict[str,dict[str,str]]] = json.load(f)
    config["go"]["aliases"][alias] = real
    with open("config.json", "w") as f:
        json.dump(config, f, indent=4)
    

def setalias_list(real, alias):
    with open("config.json") as f:
        config:dict[str,dict[str,dict[str,str]]] = json.load(f)
    config["listdir"]["aliases"][real] = alias

