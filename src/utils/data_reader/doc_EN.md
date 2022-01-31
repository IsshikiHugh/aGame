# `QWQreader` Documentation

The tool is used to deal with data files used in aGame, whose suffix is `.qwq`.

## `.qwq` grammar

0. Case sensitive.
1. All keywords should be separated by at least one space.
2. You are supposed to use the form like : `tag { key-val pairs }`
3. Several values leading by only one key is logical. Using form like `key : val1 , val2 , ... ;`, which means you should separated values with ` , `, and put a ` ; ` at the end.
4. Annotation can be written like `# Annotations #`.
5. Adjacent spaces are always seemed as one.
6. Pay attention to that keywords without space around will be seemed as a normal word. In other words, using keywords like `<space><keywords><space>` is always ideal.

```qwq
# example #
tag {
    key1 : val1 , val2 ;
    key2 : val3 ;
    key3 : val.pre val.suf ;
    # You can write comments here. #
}

```