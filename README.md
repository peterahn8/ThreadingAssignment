# Build instructions

## 1) Tooling
### On macOS
Xcode CLI tools comes with `make`:
```sh
xcode-select --install
```
[Or get it via Homebrew](https://formulae.brew.sh/formula/make). This version gets installed to PATH as `gmake`

### On Linux
Tested w/ Lubuntu. Should work same in Debian/Ubuntu:
```sh
sudo apt update
sudo apt install -y build-essential
```

## 2) Build
Run from repo root:
```sh
make
```

## 3) Run
```sh
make run
```
Executable outputs to:
- `build/ThreadingAssignment`

## 4) Clean
```sh
make clean
```