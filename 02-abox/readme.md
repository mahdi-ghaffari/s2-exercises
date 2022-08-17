# Draw Ascii Box

Draw text box with given height and width.

## Usage Example
```
    > abox.exe 3 5

    *****
    *   *
    *****

    > abox.exe 4 9

    *********
    *       *
    *       *
    *********

```


## Bounce Options
You can add optional arguments to the box-drawing

### Draw Character
Optionally get draw character

```
    > abox.exe 5 5 x

    xxxxx
    x   x
    x   x
    x   x
    xxxxx
```


### Wire Draw
Accept `wire` instead of character to draw nicer box!


```
    > abox.exe 6 6 wire

    +----+
    |    |
    |    |
    |    |
    |    |
    +----+
```

### Report Invalid Arguments (plus return code)

```
    > abox.exe
    Invalid arguments.
    Usage abox HEIGHT WIDTH [OPTIONS]


    > abox.exe 12 b
    Invalid arguments.
    Usage abox HEIGHT WIDTH [OPTIONS]

```
