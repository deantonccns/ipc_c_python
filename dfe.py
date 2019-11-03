#!/usr/bin/env python3

import os
import time

fifo_name = "fifo"
try:
    os.mkfifo(fifo_name)

except FileExistsError:
    pass

with open(fifo_name, "wb") as pipe:
    n_size = 8  # size of a frame
    index = 0
    while True:
        pipe.write(bytearray([index] * n_size))
        pipe.flush()
        time.sleep(500 / 1000)
        index = 0 if index == 255 else index + 1

os.remove("fifo")    # delete