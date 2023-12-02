from typing import Optional, Literal
from subprocess import Popen, PIPE, STDOUT
import os

CPP_BUILD_COMMAND = "clang++ %s -o a.out -O3 -DPART1 -std=c++2b"

def main(
    year: Optional[int],
    day: Optional[int],
    lang: Literal["rs"] | Literal["cpp"],
):
    folder_path = fr"""./{year}/{day}/"""

    match lang:
        case "cpp": 
            exec_path = os.path.join(folder_path, "main.cpp")
            cmd = CPP_BUILD_COMMAND % exec_path
            os.system(cmd)
            input_path = os.path.join(folder_path, "input.txt")
            with open(input_path) as input:
                process = Popen('./a.out', stdin=PIPE, stderr=STDOUT, stdout=PIPE)
                stdout = process.communicate(input=input.read().encode())[0]
                out = str(stdout.decode()).strip()
                print(out)


if __name__ == "__main__":
    main(2023, 1, "cpp")
