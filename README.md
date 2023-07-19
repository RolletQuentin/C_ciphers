# To compile the project, please run :
```shell
make
```

# To generate the documentation, please run :
```shell
make doc
```
or
```shell
doxygen Doxyfile
```

# To run the project, please run :
```shell
./bin/main
```
You have few arguments :\
  -c : to give the encryption code you want to use\
  -m : the message you want to encrypt\
  -d : (for Cesar code) the gap you want\
  -k : (for Vigenere code) the key for the encryption of the message

There are few examples to run the project with arguments :

```shell
./bin/main -c cesar -m "The message to encrypt" -d 5
```

```shell
./bin/main -c vigenere -m "The message to encrypt" -k "The key you want to use"
```

```shell
./bin/main -c scytale -m "The message to encrypt"
```
