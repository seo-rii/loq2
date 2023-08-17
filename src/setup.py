import setuptools
import glob

cpps = glob.glob('./loq2/native/**/*.cpp', recursive=True)
headers = glob.glob('./loq2/native/**/*.h', recursive=True)

native = setuptools.Extension('native', sources=cpps, headers=headers, extra_compile_args=['-std=c++20', '-O3'],
                              language='c++')

install_requires = [
    'numpy==1.25.2',
    'ctypes==1.1.0',
]

setuptools.setup(
    name="loq2",
    version="0.2.2",
    author="seorii",
    author_email="me@seorii.page",
    description="League of Quoridor",
    long_description="League of Quoridor",
    long_description_content_type="text/markdown",
    url="https://github.com/seo-rii/loq2",
    packages=setuptools.find_packages(),
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: MIT License",
        "Operating System :: OS Independent",
    ],
    python_requires='>=3.6',
    ext_modules=[native],
)
