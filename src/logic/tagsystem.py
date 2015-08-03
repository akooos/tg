class AttributeType:
    __init__():
        self.name=""
        self.valueType=""
        self.appliedFor=[]
        self.possiblevalues=[]

class BaseTagType:
    __init__(name="",length=0):
        __name=name
        __length=length
class TagSystem:
    __init__(name):
        self.name = name
    def getSupportedTagTypes():
        return []
    def getSupportedAttributes():
        return []
    def getTagTypeDesc(tagtypename, lang=""):
        return ""
    def getAttributeDesc(attr,lang=""):
        return ""
    def export(project,path):
        return False
    def import(path,project):
        return False 
