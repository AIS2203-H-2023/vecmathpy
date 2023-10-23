import os
import subprocess
from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext

WINDOWS = (os.name == 'nt')

buildFolder = "build"


def version():
    with open("../version.txt", "r") as f:
        return f.readline().strip()


class CMakeExtension(Extension):

    def __init__(self, name):
        super().__init__(name, sources=[])


class CMakeBuild(build_ext):

    def run(self):
        for ext in self.extensions:
            self.build_extension(ext)
        super().run()

    def build_extension(self, ext):

        build_type = 'Release'
        # configure
        cmake_args = [
            'cmake',
            '..',
            '-B',
            buildFolder,
            '-DCMAKE_BUILD_TYPE={}'.format(build_type)
        ]
        if WINDOWS:
            cmake_args.extend(['-A', 'x64'])

        subprocess.check_call(cmake_args)
        cmake_args_build = [
            'cmake',
            '--build',
            buildFolder
        ]
        if WINDOWS:
            cmake_args_build.extend(['--config', 'Release'])
        subprocess.check_call(cmake_args_build)


setup(name="pycpp",
    version=version(),
    description="Python cpp wrapper demo",
    url="https://github.com/AIS2203-H-2022/python-wrapper-demo",
    license="MIT",
    ext_modules=[CMakeExtension('pycpp')],
    cmdclass=dict(build_ext=CMakeBuild),
)
