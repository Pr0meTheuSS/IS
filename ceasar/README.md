# help
```
~/Р/i/IS/ceasar/build/Release feature/ceasar ?1 ❯ ./ceasar --help                                                    х INT 17:16:34
Caesar cipher CLI tool
Usage:
  caesar [OPTION...]

  -m, --mode arg  Mode: enc | dec | brute | dict
  -t, --text arg  Input text (default: "")
  -f, --file arg  Path to txt file (default: "")
  -o, --out arg   Output file path (default: "")
  -k, --key arg   Shift key (for enc/dec) (default: 0)
  -d, --dict arg  Dictionary file (for dict mode) (default: "")
  -h, --help      Show help
```
# manual test
- cd ./build/Release
- echo "hello world" > input.txt


1. ./ceasar --mode enc --file input.txt --key 3 --out out.txt
2. ./ceasar --mode dec --file out.txt --key 3
3. ./ceasar --mode brute --file out.txt
4. ./ceasar --mode dict --file out.txt --dict /etc/dictionaries-common/words  
