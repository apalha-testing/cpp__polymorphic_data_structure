# cpp__polymorphic_data_structure

## Build
Build is done in two stages:
1. Compile the `eos` library.
2. Compile the example.

### Build `eos` library
Switch to the `eos` folder.

```
cd eos
```

Edit the `conf.mk` file to comply with your system. Essentially, you need to change the compiler. In most cases `CXX = g++` and `CC = gcc` should work.

Then run make

```
make
```

If this was successful you should have a file `libeos_polymorphism.a`. You can now go on to the next step.

### Build example
Swith to the `examples` folder. If you are still in the `eos` folder do

```
cd ../examples
```

Follow the same procedure as described above to edit the `conf.mk` file to suite your needs.

Then run make

```
make
```

If this was successful you should have a new executable named `example_eos_polymorphism`.
