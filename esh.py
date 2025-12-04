from go import go
import os, re, time
from colorama import init, Fore, Back, Style
from list import listdir
import config
import json
init()
def main():
    try:
        while True:
            command = input(f" {os.getcwd()} $ ")
            cmd: list[str] = re.split(r'\s+(?=(?:[^"]*"[^"]*")*[^"]*$)', command)
            if cmd[0] == "go":
                go(" ".join(cmd[1:]))
            elif cmd[0] == "exit":
                break
            elif cmd[0] == "list":
                if len(cmd) == 2:
                    listdir(cmd[1])
                    continue
                listdir()
            elif cmd[0] == "setalias":
                if cmd[1] == "go":
                    config.setalias_go(cmd[3], cmd[2])
                if cmd[1] == "list":
                    config.setalias_list(cmd[2], cmd[3])
            else:
                os.system(command)
    except KeyboardInterrupt as KI:
        print(f"""
    {Fore.RED}Keyboard interrupt {Fore.YELLOW}ctrl + c:""", end="")
        time.sleep(1)
        print(f"""
        exit of esh{Style.RESET_ALL}""")
        exit()
    except FileNotFoundError as error:
        if error.filename == "config.json":
            with open("config.json", "w") as cj:
                json.dump({
                    "go":{"aliases":{}},
                    "listdir":{"aliases":{}}},
                    cj,
                    indent=4
                )
            print(f"{Fore.LIGHTYELLOW_EX}archivo de configuración no encontrado, intente de nuevo despues de crearse el nuevo archivo{Fore.RESET}")
            time.sleep(0.3)
            print(f"{Fore.LIGHTGREEN_EX}nuevo archivo creado{Fore.RESET}")
        else:
            raise error
    else:
        print(f"""
    {Fore.LIGHTGREEN_EX}exit of esh{Style.RESET_ALL}""")

main()