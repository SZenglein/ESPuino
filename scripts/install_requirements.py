# install.py
import subprocess
import sys
from pathlib import Path

req_file = Path("scripts/requirements.txt")

if not req_file.exists():
    print("requirements.txt not found.")
    sys.exit(1)

print(f"Installing from {req_file}...")
subprocess.check_call([sys.executable, "-m", "pip", "install", "-r", str(req_file)])
print("Python script dependencies installed.")
