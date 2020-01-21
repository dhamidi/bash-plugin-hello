# Description

This repository holds the basic skeleton for building a bash plugin that can be loaded using `enable`.

# Prerequisites

The code is set up to work under a stock installation of the latest Ubuntu with the package `bash-builtins` installed:

```
sudo apt install -y bash-builtins
```

# Compiling

Run `make` to compile the builtin.  This will produce a file called `hello.so`.

You can load this into a running bash shell with `enable -f ./hello.so hello`.

After running that command, a new command `hello` will be available in your shell.

# Testing

Run `make test` to build the plugin, load it into temporary shell and produce some output.

You'll probably want to use more extensive tests using `expect` or something similar.
