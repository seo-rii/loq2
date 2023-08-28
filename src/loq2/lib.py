import ctypes
import glob
import os

so = glob.glob(os.path.abspath(os.path.join(__file__, '../../**/*.so')), recursive=True)
if len(so) == 0:
    so = glob.glob(os.path.abspath(os.path.join(__file__, '../../**/*.lib')), recursive=True)
if len(so) == 0:
    so = glob.glob(os.path.abspath(os.path.join(__file__, '../../**/*.dll')), recursive=True)
if len(so) == 0:
    so = glob.glob(os.path.abspath(os.path.join(__file__, '../../**/*.dylib')), recursive=True)
if len(so) == 0:
    raise ImportError("Cannot import native library")

lib = ctypes.cdll.LoadLibrary(so[0])
