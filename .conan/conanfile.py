from conans import ConanFile, CMake, tools

class App_Name(ConanFile):
    name = "Implicit-Sharing-Class"
    # version = "$Version_Number"
    # version = "0.1.0"
    # author = "$Author_Name"
    description = "Implicit Sharing Class"
    topics = ( "cpp", 'example', "conan" )
    settings = "os", "compiler", "build_type", "arch"
    requires = "gtest/1.10.0"
    generators = "cmake"

    def configure(self):
        pass
        # self.options["$Dependent_Lib"].shared = True
        # self.options["poco"].shared = True

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def imports(self):
        self.copy("*.dll", dst="bin", src="bin")
        self.copy("*.dylib*", dst="bin", src="lib")
