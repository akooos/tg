#include "intouch.h"

#include <fstream>

Tg::TagSystems::InTouch::InTouch() : Tg::TagSystems::TagSystem("InTouch")
{
  
  //Tg::TagSystems::setStandardPropertiesAndTypes(this);
 
  setTagBaseTypeInfo( "AlarmGroup",0);
  setTagBaseTypeInfo("IOAccess", 0 );
  setTagBaseTypeInfo("MemoryDisc",1);
  setTagBaseTypeInfo("IODisc",1);
  setTagBaseTypeInfo("MemoryInt",4);
  setTagBaseTypeInfo("IOInt",4);
  setTagBaseTypeInfo("MemoryReal",4);
  setTagBaseTypeInfo("IOReal",4);
  setTagBaseTypeInfo("MemoryMsg",0);  
  setTagBaseTypeInfo("IOMsg",0);
  setTagBaseTypeInfo("GroupVar",0);
  setTagBaseTypeInfo("HistTrend",4);
  setTagBaseTypeInfo("TagId",4);
  setTagBaseTypeInfo("IndirectDisc",1);
  setTagBaseTypeInfo("IndirectAnalog",0);  
  setTagBaseTypeInfo("IndirectMsg",0);   
  
  
  setPropertyInfo( "mode",
                            {"Project"},							
                            "Specifies how duplicate tag records are \
                              handled when importing the contents of\
                              the DBLoad file to an application’s\
                              Tagname Dictionary.",
                            "ask",
                            { "ask","replace","update","ignore",
                              "terminate","test"}
						   );
  
  setPropertyInfo( "Application",
                          Tg::TagSystems::String,
                          {"IOAccess"},
                            "Application name defined for the Access Name.",
                            "");
  
  setPropertyInfo( "Topic",
                          Tg::TagSystems::String,
                          {"IOAccess"},
                            "Topic name defined for the Access  Name",
                            " "
                          );
  setPropertyInfo( "AdviseActive",                          
                          {"IOAccess"},                         
                          "What information to poll from the \
                              server No = Advise all items \
                              Yes = Advise only active items",
                            "Yes",
                            {"No","Yes"}
                          );
  setPropertyInfo( "DDEProtocol",                          
                          {"IOAccess"}, 
                          "Communication protocol defined \
                              for the Access Name \
                              No = Suitelink, \
                              Yes = DDE, \
                              MX = Message Exchange",
                            "No",
                            {"No","Yes","MX"}
                          );
  setPropertyInfo( "SecApplication",
                          Tg::TagSystems::String,
                          {"IOAccess"},
                            "Application name defined for the \
                              secondary source of the Access  \
                              Name",
                          ""
                 );
  setPropertyInfo( "SecTopic",
                          Tg::TagSystems::String,
                          {"IOAccess"},
                            "Topic name defined for the \
                              secondary source of the Access \
                              Name.",
                          ""
                 );
  setPropertyInfo( "SecAdviseActive",                         
                          {"IOAccess"},                          
                            "When to poll information stored on \
                       the secondary server \
                       NO = Advise all items \
                       YES = Advise only active items",                   
                            "",
                          {"No","Yes"}
 
                 );
  setPropertyInfo( "SecDDEProtocol",                          
                          {"IOAccess"},                                  
                            "Communication protocol defined \
                        for the secondary source of the \
                        Access Name\
                        NO = Suitelink\
                        YES = DDE\
                        MX = Message Exchange",
                              "No",
                              {"No","Yes","MX"}
                 );
  setPropertyInfo( "FailoverExpression",
                            Tg::TagSystems::String,
                            {"IOAccess"},
                            "Failover expression that switches \
                        the Access Name to the secondary \
                        source when TRUE",
                            ""
                 ); 
  setPropertyInfo( "FailoverDeadband",
                          Tg::TagSystems::Int,
                          {"IOAccess"},
                            "Integer number of seconds\
                        before starting failover to the secondary \
                        source defined by the Access Name",
                            ""        
                 
    
  );
  setPropertyInfo( "DFOFlag",
                            
                           {"IOAccess"},
                            "Disable Failover flag \
                        Yes = Disable Failover flag set \
                        No = Disable Failover flag not set",
                            "Yes",
                            {"Yes","No"}
    
  );
  setPropertyInfo( "FBDFlag",                            
                            {"IOAccess"},
                              "Switch back to Primary flag \
                         YES = Switch back to the Primary \
                         source after the failover condition \
                         clears NO = Do not switch back \
                         to the Primary source after the \
                         failover condition clears",
                              "Yes",
                                {"Yes","No"}
                              
                 );
  setPropertyInfo( "FailbackDeadband",
                            Tg::TagSystems::Int,
                            {"IOAccess"},
                              "Integer number of seconds before \
                         switching back to the primary \
                         Access Name source after the \
                         failover condition clears",
                              "0"
                 );
  
  
  
setPropertyInfo("Group",
                          Tg::TagSystems::String,
                        {"AlarmGroup","MemoryDisc","IODisc","MemoryInt",
                          "IOInt","MemoryReal","IOReal","MemoryMsg",
                          "IOMsg","GroupVar","HistoryTrend","TagID",
                          "IndirectDisc","IndirectAnalog","IndirectMsg"},
                          "Name of the alarm group",
                          "$System"
);
setPropertyInfo("Comment",
                          Tg::TagSystems::String,
                          {"AlarmGroup","MemoryDisc","IODisc","MemoryInt",
                            "IOInt","MemoryReal","IOReal","MemoryMsg",
                            "IOMsg","GroupVar","HistoryTrend","TagID",
                            "IndirectDisc","IndirectAnalog","IndirectMsg"},
                            "Comment assigned to the alarm \
                        group Any text string",
                            ""
);

setPropertyInfo("EventLogged",
                      Tg::TagSystems::Bool,                      
                      {"AlarmGroup","MemoryDisc","IODisc","MemoryInt",
                        "IOInt","MemoryReal","IOReal","MemoryMsg",
                        "IOMsg","IndirectDisc","IndirectAnalog","IndirectMsg"},
                        "Event logging enabled or disabled",
                        "No"
);
setPropertyInfo("EventLoggingPriority",
                          Tg::TagSystems::Int,
                          { "AlarmGroup","MemoryDisc","IODisc",
                             "MemoryInt","IOInt","MemoryReal",
                             "IOReal","MemoryMsg","IOMsg",
                             "IndirectDisc","IndirectAnalog","IndirectMsg"},
                              "Priority assigned to events 1 to 999,\
                         0 = not logged",
                             "0"                          
);
setPropertyInfo("LoLoAlarmDisable",
                          Tg::TagSystems::Bool,
                          {"AlarmGroup","MemoryInt","IOInt",                     
                            "MemoryReal","IOReal"},
                            "LoLo alarm disabled or enable \
                        0 = LoLo alarm enabled \
                        1 = LoLo alarm disabled",
                            "0"
);
setPropertyInfo("LoAlarmDisable",
                Tg::TagSystems::Bool,
                {"AlarmGroup","MemoryInt","IOInt",
                  "MemoryReal","IOReal"} ,
                "Low alarm disabled or enabled\
              0 = Low alarm enabled \
              1 = Low alarm disabled",
                "0"  
);
setPropertyInfo("HiAlarmDisable",
                        Tg::TagSystems::Bool,
                        {"AlarmGroup","MemoryInt","IOInt",
                          "MemoryReal","IOReal"},
                        "High alarm disabled or enabled \
                    0 = High alarm enabled\
                    1 = High alarm disabled",
                        "0"
);
setPropertyInfo("HiHiAlarmDisable",
                          Tg::TagSystems::Bool,
                        {"AlarmGroup","MemoryInt","IOInt",
                           "MemoryReal","IOReal"},
                           "HiHi alarm disabled or enabled\
                       0 = HiHi alarm enabled \
                       1 = HiHi alarm disabled",
                        "0"
);
setPropertyInfo("MinDevAlarmDisable",
                          Tg::TagSystems::Bool,
                        {"AlarmGroup","MemoryInt","IOInt",
                          "MemoryReal","IOReal"},
                          "Minor Deviation alarm disabled \
                      or enabled 0 = Minor Deviation alarm \
                      enabled 1 = Minor Deviation alarm \
                      disabled",
                          "0"
);
setPropertyInfo("MajDevAlarmDisable",
                          Tg::TagSystems::Bool,
                          {"AlarmGroup","MemoryInt","IOInt",
                            "MemoryReal","IOReal"},
                            "Major Deviation alarm disabled \
                        or enabled 0 = Major Deviation alarm \
                        enabled 1 = Major Deviation alarm \
                        disabled",
                             "0"
);
setPropertyInfo("RocAlarmDisable",
                         Tg::TagSystems::Bool,
                          {"AlarmGroup","MemoryInt","IOInt",
                            "MemoryReal","IOReal"},
                            "Rate of Change alarm disabled or enabled \
                       0 = ROC alarm enabled \
                       1 = ROC alarm disabled",
                            "0" 
);
setPropertyInfo("DSCAlarmDisable",
                          Tg::TagSystems::Bool,
                          {"AlarmGroup","MemoryDisc","IODisc"},
                            "Discrete alarms disabled or enabled\
                       0 = Discrete alarm enabled \
                       1 = Discrete alarm disabled",
                            "0"
  
);
setPropertyInfo( "LoLoAlarmInhibitor",
                            Tg::TagSystems::String,
                            {"AlarmGroup","MemoryInt","IOInt",
                              "MemoryReal","IOReal"},
                              "Name of the tag used to inhibit \
                         LoLo alarms Tag reference: any discrete or \
                         analog tag",
                              ""
  
);
setPropertyInfo("LoAlarmInhibitor",
                        Tg::TagSystems::String,
                        {"AlarmGroup","MemoryInt","IOInt",
                          "MemoryReal","IOReal"},
                          "Name of the tag used to inhibit \
                           Low alarms Tag reference: any discrete or \
                            analog tag",
                          ""  
);
setPropertyInfo("HiAlarmInhibitor",
                        Tg::TagSystems::String,
                      {"AlarmGroup","MemoryInt","IOInt",
                        "MemoryReal","IOReal"},
                        "Name of the tag used to inhibit\
                         High alarms Tag reference: Any discrete or \
                         analog tag",
                      ""
);
setPropertyInfo("HiHiAlarmInhibitor",
                        Tg::TagSystems::String,
                        {"AlarmGroup","MemoryInt","IOInt",
                         "MemoryReal","IOReal"},
                         "Name of the tag used to inhibit \
                          HiHi alarms Tag reference: Any discrete \
                          or analog tag",
                        ""
  
);
setPropertyInfo("MinDevAlarmInhibitor",
                         Tg::TagSystems::String,
                         {"AlarmGroup","MemoryInt","IOInt",
                         "MemoryReal","IOReal"},
                         "Name of the tag used to inhibit\
                           Minor Deviation alarms\
                          Tag reference: Any discrete or \
                          analog tag Name of the tag used to \
                          inhibit",
                         ""
  
);
setPropertyInfo("MajDevAlarmInhibitor",
                        Tg::TagSystems::String,
                        {"AlarmGroup","MemoryInt","IOInt",
                          "MemoryReal","IOReal"},
                          "Name of the tag used to inhibit \
                            Major Deviation alarms \
                            Tag reference: Any discrete or \
                            analog tag",
                          ""
);
setPropertyInfo("RocAlarmInhibitor",
                        Tg::TagSystems::String,
                        {"AlarmGroup","MemoryInt","IOInt",
                          "MemoryReal","IOReal"},
                          "Name of the tag used to inhibit \
                            Rate of Change alarms \
                            Tag reference: Any discrete or \
                            analog tag",
                          ""
);
setPropertyInfo("DSCAlarmInhibitor",
                        Tg::TagSystems::String,
                        {"AlarmGroup","MemoryDisc","IODisc"},
                          "Name of the tag used to inhibit \
                           discrete alarms \
                           Tag reference: any discrete or \
                           analog tag",
                        ""  
);
setPropertyInfo("Logged",                        
                        {"MemoryDisc","IODisc","MemoryInt","IOInt",
                          "MemoryReal","IOReal","MemoryMsg","IOMsg"},
                          "Tag value logging enabled or disabled \
                            No or Off = Logging disabled \
                            Yes or On = Logging enabled",
                          "No",
                          {"No","Off","Yes","On"}
);
setPropertyInfo("RetentiveValue",                        
                        {"MemoryDisc","IODisc","MemoryInt",
                          "IOInt","MemoryReal","IOReal",
                          "MemoryMsg","IOMsg","IndirectDisc",
                          "IndirectAnalog","IndirectMsg"},
                          "Tag Retentive Value enabled or disabled \
                            0, Off, False, or No = Disabled \
                            1, On, True, or Yes = Enabled",
                         "No",
                        {"No","Off","False","Yes","On","True"} 
);
setPropertyInfo("InitialDisc",
                        {"MemoryDisc","IODisc"},
                          "Initial value assigned to discrete tag \
                            0, Off, False, or No = Off \
                            1, On, True, or Yes = On",
                          "0",
                        {"No","Off","False","0","Yes","On","True","1"} 
                          
);
setPropertyInfo("OffMsg",
                       Tg::TagSystems::String,
                        {"MemoryDisc","IODisc"},
                          "Discrete tag Off message \
                           Text string",
                            ""
);
setPropertyInfo("OnMsg",
                       Tg::TagSystems::String,
                        {"MemoryDisc","IODisc"},
                          "Discrete tag On message \
                           Text string",
                        ""
);
setPropertyInfo("AlarmState",                        
                        {"MemoryDisc","IODisc"},
                          "Tag alarm state \
                          On, Off, or None",
                        "None",
                        {"None","On","Off"}
);
setPropertyInfo("AlarmPri",
                        Tg::TagSystems::Int,
                        {"MemoryDisc","IODisc"},
                          "Alarm priority assigned to the tag \
                           1 to 999",
                        "1"
);
setPropertyInfo("AlarmComment",
                        Tg::TagSystems::String,
                        {"MemoryDisc","IODisc","MemoryInt","IOInt",
                          "MemoryReal","IOReal","MemoryMsg","IOMsg"},
                          "Alarm comment assigned to the tag \
                          Text string",
                         ""
               );       
setPropertyInfo("AlarmAckModel",                       
                       {"MemoryDisc","IODisc","MemoryInt",
                         "IOInt","MemoryReal","IOReal"},
                         "Alarm acknowledgement model \
                          Integer \
                          0 = Condition \
                          1 = Event Oriented \
                          2 = Expanded Summary",
                         "0",
                        {"0","1","2"}
  
);
setPropertyInfo("SymbolicName",
                        Tg::TagSystems::String,
                        {"MemoryDisc","IODisc","MemoryInt","IOInt",
                          "MemoryReal","IOReal","MemoryMsg","IOMsg",
                          "GroupVar","HistoryTrend","IndirectDisc",
                          "IndirectAnalog","IndirectMsg"},
                          "Symbolic name assigned to input data \
                           blocks by the Wonderware S7 Tag \
                           Creator product. Symbolic names are \
                           listed in the S7 Tag Creator Symbol \
                          Table.",
                          ""
);
setPropertyInfo("DConversion",                        
                        {"IODisc"},
                        "Input conversation: Direct or Reverse",
                        "Direct",
                        {"Direct","Reverse"}
);
setPropertyInfo("AccessName",
                        Tg::TagSystems::String,
                        {"IODisc","IOInt","IOReal","IOMsg"},
                          "InTouch Access Name assigned to tag",
                          ""  
);
setPropertyInfo("ItemUseTagname",                        
                        {"IODisc","IOInt","IOReal","IOMsg"},
                          "Use Tagname as Item Name option \
                           enabled or disabled No or False = \
                          Disabled Yes or True = Enabled",
                        "No",
                        {"No","False","Yes","True"}
                        
);
setPropertyInfo("ItemName",
                        Tg::TagSystems::String,
                        {"IODisc","IOInt","IOReal","IOMsg"},
                          "Name of the item assigned to the tag \
                           Text string",
                        ""  
);
setPropertyInfo("ReadOnly",                        
                        {"IODisc","IOInt","IOReal","IOMsg"},
                        "Tag value read only or read/write \
                          Yes = Read Only \
                          No = Read/Write",
                        "No",
                        {"Yes","No"}
);
setPropertyInfo("RetentiveAlarmParameters",                         
                        {"MemoryInt","IOInt","MemoryReal","IOReal"},
                          "Tag Retentive Parameters enabled or \
                            disabled No or Off = Disabled \
                            Yes or On = Enabled",
                        "No",
                       {"Yes","No","On","Off"}
                            
);
setPropertyInfo("AlarmValueDeadband",
                         Tg::TagSystems::Float,
                         {"MemoryInt","IOInt","MemoryReal","IOReal"},
                          "Tag alarm deadband",
                          "0"  
);
setPropertyInfo("AlarmDevDeadband",
                         Tg::TagSystems::Float,
                          {"MemoryInt","IOInt","MemoryReal","IOReal"},
                            "Tag deviation alarm deadband",
                          ""  
);
setPropertyInfo("EngUnits",
                        Tg::TagSystems::String,
                        {"MemoryInt","IOInt","MemoryReal","IOReal"},
                          "Engineering units assigned to tag",
                          ""  
);
setPropertyInfo("InitialValue",
                        Tg::TagSystems::Float,
                        {"MemoryInt","IOInt","MemoryReal","IOReal"},
                          "Initial value assigned to the tag",
                        "0"  
);
setPropertyInfo("MinValue",
                        Tg::TagSystems::Float,
                        {"MemoryInt","MemoryReal"},
                          "Minimum value assigned to the tag",
                          "-32768"
);
setPropertyInfo("MaxValue",
                        Tg::TagSystems::Float,
                        {"MemoryInt","MemoryReal"},
                          "Maximum value assigned to the tag",
                          "32767"
);
setPropertyInfo("Deadband",
                        Tg::TagSystems::Float,
                        {"MemoryInt","IOInt",
                          "MemoryReal","IOReal"},
                          "Value deadband assigned to the tag",
                         "0"
);
setPropertyInfo("LogDeadband",
                        Tg::TagSystems::String,
                        {"MemoryInt","IOInt","MemoryReal","IOReal"},
                          "Logging deadband assigned to the tag",
                          "0"
);
setPropertyInfo("LoLoAlarmState",                        
                        {"MemoryInt","IOInt","MemoryReal","IOReal"},
                          "LoLo alarm enabled or disabled \
                          No or Off = Disabled \
                          Yes or On = Enabled",
                        "No",
                        {"No","Yes","Off","On"}
);
setPropertyInfo("LoLoAlarmValue",
                        Tg::TagSystems::Float,
                        {"MemoryInt","IOInt","MemoryReal","IOReal"},
                          "LoLo alarm point assigned to tag",
                        "0"
);
setPropertyInfo("LoLoAlarmPri",
                        Tg::TagSystems::Int,
                        {"MemoryInt","IOInt","MemoryReal","IOReal"},
                          "Priority assigned to LoLo alarm \
                           1 to 999",
                          "1" 
);
setPropertyInfo("LoAlarmState",
                        {"MemoryInt","IOInt","MemoryReal","IOReal"},
                          "Low alarm enabled or disabled \
                          No or Off = Disabled \
                          Yes or On = Enabled",
                        "No",
                        {"No","Yes","Off","On"}
);
setPropertyInfo("LoAlarmValue",
                        Tg::TagSystems::Float,
                        {"MemoryInt","IOInt","MemoryReal","IOReal"},
                          "Low alarm point assigned to tag",
                        "0"
);
setPropertyInfo("LoAlarmPri",
                       Tg::TagSystems::Int,
                       {"MemoryInt","IOInt","MemoryReal","IOReal"},
                          "Priority assigned to Low alarm \
                           1 to 999",
                           "1"  
);
setPropertyInfo("HiAlarmState",                        
                        {"MemoryInt","IOInt","MemoryReal","IOReal"},
                          "High alarm enabled or disabled \
                            No or Off = Disabled \
                            Yes or On = Enabled",
                        "No",
                        {"No","Off","Yes","On"}
);
setPropertyInfo("HiAlarmValue",
                        Tg::TagSystems::Float,
                        {"MemoryInt","IOInt","MemoryReal","IOReal"},
                          "High alarm point assigned to tag",
                        "0"  
);
setPropertyInfo("HiAlarmPri",
                        Tg::TagSystems::Int,
                        {"MemoryInt","IOInt","MemoryReal","IOReal"},
                          "Priority assigned to High alarm \
                          1 to 999",
                          "1"
);
setPropertyInfo("HiHiAlarmState",                        
                        {"MemoryInt","IOInt","MemoryReal","IOReal"},
                          "HiHi alarm enabled or disabled \
                            No or Off = Disabled \
                            Yes or On = Enabled",
                         "No",
                          {"No","Yes","Off","On"}
);
setPropertyInfo("HiHiAlarmValue",
                        Tg::TagSystems::Float,
                          {"MemoryInt","IOInt","MemoryReal","IOReal"},
                          "HiHi alarm point assigned to tag",
                          "0"
 );
setPropertyInfo("HiHiAlarmPri",
                        Tg::TagSystems::Int,
                        {"MemoryInt","IOInt","MemoryReal","IOReal"},
                        "Priority assigned to HiHi alarm \
                          1 to 999",
                        "1"
);
setPropertyInfo("MinorDevAlarmState",                        
                        {"MemoryInt","IOInt","MemoryReal","IOReal"},
                          "Minor deviation alarm enabled or \
                           disabled No or Off = Disabled \
                          Yes or On = Enabled \
                          Minor deviation alarm percentage",
                         "No" ,
                        {"No","Yes","Off","On"}
                        
);
setPropertyInfo("MinorDevAlarmValue",
                        Tg::TagSystems::String,
                        {"MemoryInt","IOInt","MemoryReal","IOReal"},
                          "Minor deviation alarm percentage \
                            assigned to tag",
                        "0"
);
setPropertyInfo("MinorDevAlarmPri",
                        Tg::TagSystems::Int,
                        {"MemoryInt","IOInt","MemoryReal","IOReal"},
                          "Priority assigned to Minor Deviation \
                          alarm 1 to 999",
                        "1"
);
setPropertyInfo("MajorDevAlarmState",                        
                        {"MemoryInt","IOInt","MemoryReal","IOReal"},
                          "Major deviation alarm enabled or \
                           disabled \
                          No or Off = Disabled \
                          Yes or On = Enabled",
                        "No",
                        {"No","Yes","Off","On"}
);
setPropertyInfo("MajorDevAlarmValue",
                        Tg::TagSystems::Float,
                        {"MemoryInt","IOInt","MemoryReal","IOReal"},
                          "Major deviation alarm percentage \
                           assigned to tag",
                         "0"
);
setPropertyInfo("MajorDevAlarmPri",
                        Tg::TagSystems::Int,
                        {"MemoryInt","IOInt","MemoryReal","IOReal"},
                          "Priority assigned to Major Deviation \
                          alarm 1 to 999",
                        "1"
);
setPropertyInfo("DevTarget",
                        Tg::TagSystems::Float,
                        {"MemoryInt","IOInt","MemoryReal","IOReal"},
                        "Tag deviation target value",
                        "0"
);
setPropertyInfo("ROCAlarmState",                        
                        {"MemoryInt","IOInt","MemoryReal","IOReal"},
                          "Rate of Change alarm enabled or disabled \
                           No or Off = Disabled \
                           Yes or On = Enabled",
                        "No",
                        {"No","Yes","Off","On"}
                        
);
setPropertyInfo("ROCAlarmValue",
                        Tg::TagSystems::Float,
                        {"MemoryInt","IOInt","MemoryReal","IOReal"},
                        "Change in tag value by percent",
                        "0"
);
setPropertyInfo("ROCAlarmPri",
                        Tg::TagSystems::Int,
                        {"MemoryInt","IOInt","MemoryReal","IOReal"},
                          "Priority assigned to Rate of Change alarm \
                          1 to 999",
                        "1"
);
setPropertyInfo("ROCTimeBase",
                        {"MemoryInt","IOInt","MemoryReal","IOReal"},
                          "Measurement period to calculate rate of change \
                          Sec, Min or Hr",
                         "Min",
                        {"Sec","Min","Hr"}
);
setPropertyInfo("MinEU",
                       Tg::TagSystems::Float,
                        {"IOInt","IOReal"},
                        "Minimum engineering units value \
                          assigned to the tag",
                        "-32768"
);
setPropertyInfo("MaxEU",
                        Tg::TagSystems::Float,
                        {"IOInt","IOReal"},
                          "Maximum engineering units value \
                            assigned to the tag",
                        "32767"
);
setPropertyInfo("MinRaw",
                        Tg::TagSystems::Float,
                        {"IOInt","IOReal"},
                        "Minimum raw value assigned to tag",
                         "-32768"
);
setPropertyInfo("MaxRaw",
                        Tg::TagSystems::Float,
                        {"IOInt","IOReal"},
                          "Maximum raw value assigned to tag",
                          "32767"
);
setPropertyInfo("Conversion",
                        {"IOInt","IOReal"},
                        "Tag value conversion:\
                        Linear or Square Root",
                        "Linear",
                        {"Linear","Squer Root"}
);
setPropertyInfo("MaxLength",
                        Tg::TagSystems::Float,
                        {"MemoryMsg","IOMsg"},
                         "Maximum message length",
                         "131"
);
setPropertyInfo( "InitialMessage",
                        Tg::TagSystems::String,
                        {"MemoryMsg","IOMsg"},
                        "Initial tag message",
                         ""
);



}
void Tg::TagSystems::InTouch::load ( 
			  std::ifstream& strm, 
			  Tg::Project&	project,
			  Tg::FileHandler::Encoding encoding )
{  
     
  const size_t BUFFER_SIZE = 512;
  char buffer[BUFFER_SIZE] = {0};
  
  strm.get(buffer,BUFFER_SIZE);  
  strm.close();
  
}
void Tg::TagSystems::InTouch::save ( 
		const Tg::Project& project, 
		std::ofstream& strm, 
		Tg::FileHandler::Encoding encoding )
{
  NOT_YET_IMPLEMENTED
}

