"""
Property has attirubtes, holds further properties
Applies to tags, or/and structures, groups in the system. 
"""
class Property:
    __init__():
        self.name  = ""
        self.props = Set([])
        self.attrs = {}
"""
Represents a tag in the system.

Note that which group it belongs, is a property 
"""
class Tag:
    __init__(name,address,tagtype):
        self.name  = name
        self.addr  = address
        self.tagtype   = tagtype
        self.props = Set([])
"""
Set of tags with the same properties.
Name is optional.
"""
class TagSet:
    __init__(name=""):
        self.name=name
        self.props = Set([])
        self.tags  = Set([])
"""
Represents primitive type 
"""
class TagType:
    __init__(name,basetype,props=Set([])):
        self.__name = name
        self.__basetype = basetype
        self.props = props
"""
"""
class TagStruct(TagType):
    __init__(name="")
        self.parts = []
"""
Represent a tag generator project
"""
class Project:
    __init__():
        self.props = Set([])
        self.name  = ""
        self.tagsystem = ""
        self.tagtypes = Set([])
        self.tagsets  = Set([])
        self.tags     = Set([])
