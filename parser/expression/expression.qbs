import qbs

Project {
    minimumQbsVersion: "1.7.1"

    StaticLibrary {
        name: "expressionTree"

        Depends { name: "blockToken" }

        files: [
            "LineView.h",
            "Tree.h",
            "TreeBuilder.h",
            "TreeOutput.h",
        ]

        Export {
            Depends { name: "cpp" }
            cpp.includePaths: [".."]

            Depends { name: "blockToken" }
        }
    }

    StaticLibrary {
        name: "expressionParser"

        Depends { name: "instance" }

        files: [
            "Parser.cpp",
            "Parser.h",
        ]

        Export {
            Depends { name: "cpp" }
            cpp.includePaths: [".."]

            Depends { name: "instance" }
        }
    }

    Application {
        name: "expressionParser.tests"
        consoleApplication: true
        type: ["application", "autotest"]

        Depends { name: "expressionParser" }
        Depends { name: "googletest" }
        googletest.useMain: true

        files: [
            "expressionParserTest.cpp",
        ]
    }
}
