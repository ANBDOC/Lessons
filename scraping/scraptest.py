#!/usr/bin/env python3
'''
Module Docstring
'''

__author__ = "ANB"
__version__ = "0.1.0"
__license__ = "MIT"

import os
import sys

def scrap(url):
    from urllib.request import urlopen
    html = urlopen(url)
    print(html.read())

def main():
    '''
    Main entry point of the app
    '''
    url='http://192.168.251.12/index.html'
    scrap(url)
    quit(0)

"""
This is executed when run from the command line
"""

if __name__ == "__main__":
    main()
