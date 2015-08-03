class AttributeType:
    def __init__(self):
        self.name=""
        self.valueType=""
        self.appliedFor=[]
        self.possiblevalues=[]

class BaseTagType:
    def __init__(self,name="",length=0):
        __name=name
        __length=length
class TagSystem:
    def __init__(self,name):
        self.name = name
    def getSupportedTagTypes(self):
        return set()
    def getSupportedAttributes(self,type):
        return set()
    def getTagTypeDesc(self,tagtypename, lang=""):
        return ""
    def getAttributeDesc(self,attr,lang=""):
        return ""
    def save(self,project,path):
        return False
    def load(self,path,project):
        return False 
