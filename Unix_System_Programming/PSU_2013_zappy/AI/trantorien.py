#!/usr/bin/env python

import os
import sys
import time
import socket
import argparse
from trantorien import *
from itertools import izip, cycle

tCenterCases = 0, 2, 6, 12, 20, 30, 42, 56
tStones = ("linemate",), ("linemate", "deraumere", "sibur"), ("linemate", "sibur", "phiras"), ("linemate", "deraumere", "sibur", "phiras"), ("linemate", "deraumere", "sibur", "mendiane"), \
           ("linemate", "deraumere", "sibur", "phiras"), ("linemate", "deraumere", "sibur", "mendiane", "phiras", "thystame")
tLevel = 1, 2, 2, 4, 4, 6, 6

class   trantorien:
    def __init__(self, team):
        self._team = team
        self._level = 1
        self._key = team
        self._target = 0
        self._voir = []
        self._inventory = []
        self._connected = 0
        self._stop = 0
        try:
            self._socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        except socket.error, msg:
            print "Failed to create socket. Error code: " + str(msg[0]) + " , Error message : " + msg[1]
            sys.exit();
        self._messages = {
            "find" : "find",
            "no" : "No",
            "yes" : "Yes"
        }
