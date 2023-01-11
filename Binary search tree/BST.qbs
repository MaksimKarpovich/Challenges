import qbs

CppApplication {

    property string Home: path
    property string BST: Home + "/BST"
    consoleApplication: true
    install: true
    files:[
        Home + "/main.c",
        BST + "/**",
    ]

    cpp.includePaths: [
        BST,
    ]
}
