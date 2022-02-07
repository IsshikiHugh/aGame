# `QWQreader` 使用文档

本工具用于识别处理aGame的`.qwq`数据文件

## `.qwq`文件 语法规范

0. 区分大小写
1. 所有**键**、**分隔符**和**键值**间都用空格隔开
2. 文件的书写层级分布为： `tag { key-val pairs }`
3. 支持单键多值，通用格式为： `key : val1 , val2 , ... ;`即用逗号分隔多键值，用分号声明语句尾，键值可以使用空格
4. 注释符号为`# 注释内容 #`
5. 同一个键值中出现多个连续空格，只会解析为一个空格
6. 关键字之间没有空格会被当做普通字符处理，也就是说真正的关键字是 `<空格><关键字><空格>`

```qwq
# .qwq文件样例 #
tag {
    key1 : val1 , val2 ;
    key2 : val3 ;
    key3 : val.pre val.suf ;
    # 缩进仅仅用来方便阅读 #
}

```

## 文档

### `QWQAnalyzer` 

#### `QWQAnalyzer newAnalyzer(string filePath)`

- 声明时输入一个string类型的变量filePath来指定配置文件路径以构造一个Analyzer。

#### `void QWQAnalyzer::analyze()`

- 调用绑定了filePath的analyzer，执行配置文件解析

#### `map< string , vector<string> > &QWQAnalyzer::getTag(string tag)`

- 输入一个string类型的tag
- 返回配置文件中对应tag的信息，以`map< string , vector<string> >`返回引用

#### `vector<string> &QWQAnalyzer::getVal(string tag , string key)`

- 输入string类型的tag和key
- 返回配置文件中对应tag和key的信息，以`vector<string>`返回引用
