import dis
import marshal

with open("__pycache__/power-of.cpython-310.pyc", "rb") as f:
    f.read(16)
    code = marshal.load(f)
    dis.dis(code)
