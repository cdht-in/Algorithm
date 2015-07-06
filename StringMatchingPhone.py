import os
import re

def MatchPhoneNumber(path):
    list = []
    if os.path.exists(path):
        with open(path) as f:
            for line in f:
                pattern = '^678|987([-|.])\d{3}([-|.])\d{4}$'
                m = re.match(pattern,line)
                if m:
                    print m.group(0)
                    list.append(line)
                    
def main():
    path = os.getcwd() + '/phone.txt'
    MatchPhoneNumber(path)

if __name__ == '__main__':
    main()