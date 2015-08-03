"""
Property has attirubtes, holds further properties
Applies to tags, or/and structures, groups in the system. 
"""


class TagProperty:
    def __init__(self):
        self.name = ""
        self.props = set()
        self.attrs = {}


"""
Represents a tag in the system.

Note that which group it belongs, is a property 
"""


class Tag:
    def __init__(self, name, address, tagtype):
        self.name = name
        self.addr = address
        self.tagtype = tagtype
        self.props = set()


"""
Set of tags with the same properties.
Name is optional.
"""


class TagSet:
    def __init__(self, name=""):
        self.name = name
        self.props = set()
        self.tags = set()


"""
Represents primitive type 
"""


class TagType:
    def __init__(self, name, basetype, props=set()):
        self.__name = name
        self.__basetype = basetype
        self.props = props


"""
"""


class TagStruct(TagType):
    def __init__(self, name=""):
        self.parts = []


"""
Represent a tag generator project
"""


class Project:
    def load(self):
        self.props = set()
        self.name = ""
        self.tagsystem = ""
        self.tagtypes = set()
        self.tagsets = set()
        self.tags = set()

    def __init__(self, locpath):
        self.location = locpath
        self.load()
