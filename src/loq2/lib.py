import ctypes
import glob

so = glob.glob('./**/*.so', recursive=True)[0]
lib = ctypes.cdll.LoadLibrary(so)
