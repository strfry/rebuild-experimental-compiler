import qbs

Project {
    minimumQbsVersion: "1.7.1"

    StaticLibrary {
        name: "vm"
        Depends { name: "cpp" }
        cpp.combineCxxSources: true
        cpp.includePaths: [".."]

        Depends { name: "instance" }

        files: [
            "Frame.cpp",
            "Frame.h",
            "Machine.cpp",
            "Machine.h",
            "Stack.cpp",
            "Stack.h",
        ]

        Export {
            Depends { name: "cpp" }
            cpp.includePaths: [".."]

            Depends { name: "instance" }
        }
    }

    Application {
        name: "execution.tests"
        consoleApplication: true
        type: ["application", "autotest"]

        Depends { name: "vm" }
        Depends { name: "googletest.lib" }
        googletest.lib.useMain: true

        files: [
            "ExecutionTests.cpp"
        ]
    }
}
