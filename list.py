import os, json 
from colorama import init, Fore
init()
def dictlistdir(path: str=".") -> dict:
    result = {}
    with open("config.json", "r") as f:
        aliases = json.load(f)["listdir"]["aliases"]
    for entry in os.listdir(path):
        full = os.path.join(path, entry)

        if os.path.isdir(full):
            # Carpeta
            result[entry] = "dir"
        else:
            # Archivo
            name, ext = os.path.splitext(entry)
            if ext in aliases:
                ext = aliases[ext]
            result[name] = ext

    return result

def listdir(path:str="."):
    dir:dict[str,str] = dictlistdir(path)
    with open("config.json", "r") as f:
        aliases: dict[str, str] = json.load(f)["listdir"]["aliases"] | {"dir":"dir"}
    lines = []
    strs = ["    {}{}--{}", "    {}{}"]
    for f, e in dir.items():
        k = 1
        v = e
        if e in aliases.values():
            k = 0
        lines.append(strs[k].format(f, z if ""!=(z:=" " * (max(len(f), len(v)) % min(len(f), len(v)))) else "    ", Fore.CYAN + v + Fore.RESET))
    result = "\n".join(lines)
    print(result)
