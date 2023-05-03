# Some cipher methods

(school project) Implementation of Cesar cipher, Vigenere cipher and Scytale cipher.

## Compilation :
```shell
make
```

## Documentation :
```shell
make doc
```

## Run :
```shell
./bin/main
```
You have few arguments :\
  -c : to give the encryption code you want to use\
  -m : the message you want to encrypt\
  -d : (for Cesar code) the gap you want\
  -k : (for Vigenere code) the key for the encryption of the message

## Examples

```shell
./bin/main -c cesar -m "The message to encrypt" -d 5
```

```shell
./bin/main -c vigenere -m "The message to encrypt" -k "The key you want to use"
```

```shell
./bin/main -c scytale -m "The message to encrypt"
```
