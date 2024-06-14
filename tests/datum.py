import subprocess
from datetime import datetime

def get_day_of_week(d, m):
    date = datetime(2009, m, d)
    return date.strftime("%A")

exe = 'bin/datum.exe'

def run(d, m):
    process = subprocess.Popen([exe], stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    output, _ = process.communicate(input=f"{d} {m}\n".encode())
    return output.decode().strip()

errors = 0
for m in range(1, 13):
    days_in_month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    for d in range(1, days_in_month[m-1] + 1):
        expected_day = get_day_of_week(d, m)
        actual_day = run(d, m)
        if expected_day != actual_day:
            print(f"Error on {d} {m}: Expected {expected_day}, got {actual_day}")
            errors += 1

print(f"Total errors: {errors}")
