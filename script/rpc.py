#!/usr/bin/env python

import sys

from rqt_rpc.rpc_module import RPCPlugin
from rqt_gui.main import Main

plugin = 'rqt_rpc'
main = Main(filename=plugin)
main.main(standalone=plugin)
#sys.exit(main.main(standalone=plugin))
