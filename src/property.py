class Property:
	__init__():
		self.props = Set([])
		self.attrs = {}
class Tag:
	__init__(name,address):
		self.name  = name
		self.addr  = address
		self.props = Set([])
class Group:
	__init__(name=""):
		self.props = Set([])
		self.tags  = Set([])
		self.name  = name
class Struct:
	__init__(name="")
		selft.props = Set([])
