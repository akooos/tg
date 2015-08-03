from src.logic.tagsystem import TagSystem


class InTouch101(TagSystem):
    def __init__(self):
        self.name="InTouch101"
    def getSupportedTagTypes(self):
        return set(['MemoryDiscrete',
                    'MemoryInt',
                    'MemoryReal',
                    'MemoryMessage'
                    'GroupVar'
                    'IODiscrete',
                    'IOInt',
                    'IOReal',
                    'IOMessage'
                    ])
    def getSupportedAttributes(self,type):
        return set([])