﻿#include "intouch.h"

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
							{ 	StdStrValue("ask"), 
								StdStrValue("replace"),
								StdStrValue("update"),
								StdStrValue("ignore"),
								StdStrValue("terminate"),
								StdStrValue("test"),
							}
						   );
  
  setPropertyInfo( "Application",
                          Tg::TagSystems::String,
                          {"IOAccess"},
                          " Application name defined for the Access Name",
                          "Valid I/O application name");
  
  setPropertyInfo( "Topic",
                          Tg::TagSystems::String,
                          {"IOAccess"},
                          " Topic name defined for the Access  Name",
                          "Valid I/O topic name "
                          );
  setPropertyInfo( "AdviseActive",
                          Tg::TagSystems::String,
                          {"IOAccess"},
                          "Yes",
                          "What information to poll from the \
                              server No = Advise all items \
                              Yes = Advise only active items"
                          );
  setPropertyInfo( "DDEProtocol",
                          Tg::TagSystems::String,
                          {"IOAccess"},
                          "  Communication protocol defined \
                              for the Access Name \
                              No = Suitelink, \
                              Yes = DDE, \
                              MX = Message Exchange",
                            "Yes"
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
                          Tg::TagSystems::String,
                          {"IOAccess"},
                            "When to poll information stored on \
                              the secondary server \
                              NO = Advise all items \
                              YES = Advise only active items",
                          ""
                          
                 );
  setPropertyInfo( "SecDDEProtocol",
                          Tg::TagSystems::String,
                          {"IOAccess"},
                            "Communication protocol defined \
                              for the secondary source of the \
                              Access Name\
                              NO = Suitelink\
                              YES = DDE\
                              MX = Message Exchange",
                          ""
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
                            Tg::TagSystems::String,
                           {"IOAccess"},
                            "Disable Failover flag \
                        Yes = Disable Failover flag set \
                        No = Disable Failover flag not set",
                            ""               
    
  );
  setPropertyInfo( "FBDFlag",
                            Tg::TagSystems::String,
                            {"IOAccess"},
                              "Switch back to Primary flag \
                         YES = Switch back to the Primary \
                         source after the failover condition \
                         clears NO = Do not switch back \
                         to the Primary source after the \
                         failover condition clears",
                              ""
                 );
  setPropertyInfo( "FailbackDeadband",
                            Tg::TagSystems::Int,
                            {"IOAccess"},
                              "Integer number of seconds before \
                         switching back to the primary \
                         Access Name source after the \
                         failover condition clears",
                              ""
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

setPropertyInfo( 
"EventLogged",Tg::TagSystems::String,{"AlarmGroup","MemoryDisc","IODisc",
"MemoryInt","IOInt","MemoryReal","IOReal","MemoryMsg","IOMsg","IndirectDisc",
"IndirectAnalog","IndirectMsg"});
setPropertyInfo( 
"EventLoggingPriority",Tg::TagSystems::String,{"AlarmGroup","MemoryDisc",
"IODisc","MemoryInt","IOInt","MemoryReal","IOReal","MemoryMsg","IOMsg",
"IndirectDisc","IndirectAnalog","IndirectMsg"});
setPropertyInfo( 
"LoLoAlarmDisable",Tg::TagSystems::String,{"AlarmGroup","MemoryInt","IOInt",
"MemoryReal","IOReal"});
setPropertyInfo( 
"LoAlarmDisable",Tg::TagSystems::String,{"AlarmGroup","MemoryInt","IOInt",
"MemoryReal","IOReal"});
setPropertyInfo( 
"HiAlarmDisable",Tg::TagSystems::String,{"AlarmGroup","MemoryInt","IOInt",
"MemoryReal","IOReal"});
setPropertyInfo( 
"HiHiAlarmDisable",Tg::TagSystems::String,{"AlarmGroup","MemoryInt","IOInt",
"MemoryReal","IOReal"});
setPropertyInfo( 
"MinDevAlarmDisable",Tg::TagSystems::String,{"AlarmGroup","MemoryInt","IOInt",
"MemoryReal","IOReal"});
setPropertyInfo( 
"MajDevAlarmDisable",Tg::TagSystems::String,{"AlarmGroup","MemoryInt","IOInt",
"MemoryReal","IOReal"});
setPropertyInfo( 
"RocAlarmDisable",Tg::TagSystems::String,{"AlarmGroup","MemoryInt","IOInt",
"MemoryReal","IOReal"});
setPropertyInfo( 
"DSCAlarmDisable",Tg::TagSystems::String,{"AlarmGroup","MemoryDisc","IODisc"});
setPropertyInfo( 
"LoLoAlarmInhibitor",Tg::TagSystems::String,{"AlarmGroup","MemoryInt","IOInt",
"MemoryReal","IOReal"});
setPropertyInfo( 
"LoAlarmInhibitor",Tg::TagSystems::String,{"AlarmGroup","MemoryInt","IOInt",
"MemoryReal","IOReal"});
setPropertyInfo( 
"HiAlarmInhibitor",Tg::TagSystems::String,{"AlarmGroup","MemoryInt","IOInt",
"MemoryReal","IOReal"});
setPropertyInfo( 
"HiHiAlarmInhibitor",Tg::TagSystems::String,{"AlarmGroup","MemoryInt","IOInt",
"MemoryReal","IOReal"});
setPropertyInfo( 
"MinDevAlarmInhibitor",Tg::TagSystems::String,{"AlarmGroup","MemoryInt","IOInt",
"MemoryReal","IOReal"});
setPropertyInfo( 
"MajDevAlarmInhibitor",Tg::TagSystems::String,{"AlarmGroup","MemoryInt","IOInt",
"MemoryReal","IOReal"});
setPropertyInfo( 
"RocAlarmInhibitor",Tg::TagSystems::String,{"AlarmGroup","MemoryInt","IOInt",
"MemoryReal","IOReal"});
setPropertyInfo( 
"DSCAlarmInhibitor",Tg::TagSystems::String,{"AlarmGroup","MemoryDisc","IODisc"})
;
setPropertyInfo( 
"Logged",Tg::TagSystems::String,{"MemoryDisc","IODisc","MemoryInt","IOInt",
"MemoryReal","IOReal","MemoryMsg","IOMsg"});
setPropertyInfo( 
"RetentiveValue",Tg::TagSystems::String,{"MemoryDisc","IODisc","MemoryInt",
"IOInt","MemoryReal","IOReal","MemoryMsg","IOMsg","IndirectDisc",
"IndirectAnalog","IndirectMsg"});
setPropertyInfo( "InitialDisc",Tg::TagSystems::String,{"MemoryDisc","IODisc"});
setPropertyInfo( "OffMsg",Tg::TagSystems::String,{"MemoryDisc","IODisc"});
setPropertyInfo( "OnMsg",Tg::TagSystems::String,{"MemoryDisc","IODisc"});
setPropertyInfo( "AlarmState",Tg::TagSystems::String,{"MemoryDisc","IODisc"});
setPropertyInfo( "AlarmPri",Tg::TagSystems::String,{"MemoryDisc","IODisc"});
setPropertyInfo( 
"AlarmComment",Tg::TagSystems::String,{"MemoryDisc","IODisc","MemoryInt","IOInt"
,"MemoryReal","IOReal","MemoryMsg","IOMsg"});
setPropertyInfo( 
"AlarmAckModel",Tg::TagSystems::String,{"MemoryDisc","IODisc","MemoryInt",
"IOInt","MemoryReal","IOReal"});
setPropertyInfo( 
"SymbolicName",Tg::TagSystems::String,{"MemoryDisc","IODisc","MemoryInt","IOInt"
,"MemoryReal","IOReal","MemoryMsg","IOMsg","GroupVar","HistoryTrend",
"IndirectDisc","IndirectAnalog","IndirectMsg"});
setPropertyInfo( "DConversion",Tg::TagSystems::String,{"IODisc"});
setPropertyInfo( 
"AccessName",Tg::TagSystems::String,{"IODisc","IOInt","IOReal","IOMsg"});
setPropertyInfo( 
"ItemUseTagname",Tg::TagSystems::String,{"IODisc","IOInt","IOReal","IOMsg"});
setPropertyInfo( 
"ItemName",Tg::TagSystems::String,{"IODisc","IOInt","IOReal","IOMsg"});
setPropertyInfo( 
"ReadOnly",Tg::TagSystems::String,{"IODisc","IOInt","IOReal","IOMsg"});
setPropertyInfo( 
"RetentiveAlarmParameters",Tg::TagSystems::String,{"MemoryInt","IOInt",
"MemoryReal","IOReal"});
setPropertyInfo( 
"AlarmValueDeadband",Tg::TagSystems::String,{"MemoryInt","IOInt","MemoryReal",
"IOReal"});
setPropertyInfo( 
"AlarmDevDeadband",Tg::TagSystems::String,{"MemoryInt","IOInt","MemoryReal",
"IOReal"});
setPropertyInfo( 
"EngUnits",Tg::TagSystems::String,{"MemoryInt","IOInt","MemoryReal","IOReal"});
setPropertyInfo( 
"InitialValue",Tg::TagSystems::String,{"MemoryInt","IOInt","MemoryReal","IOReal"
});
setPropertyInfo( "MinValue",Tg::TagSystems::String,{"MemoryInt","MemoryReal"});
setPropertyInfo( "MaxValue",Tg::TagSystems::String,{"MemoryInt","MemoryReal"});
setPropertyInfo( 
"Deadband",Tg::TagSystems::String,{"MemoryInt","IOInt","MemoryReal","IOReal"});
setPropertyInfo( 
"LogDeadband",Tg::TagSystems::String,{"MemoryInt","IOInt","MemoryReal","IOReal"}
);
setPropertyInfo( 
"LoLoAlarmState",Tg::TagSystems::String,{"MemoryInt","IOInt","MemoryReal",
"IOReal"});
setPropertyInfo( 
"LoLoAlarmValue",Tg::TagSystems::String,{"MemoryInt","IOInt","MemoryReal",
"IOReal"});
setPropertyInfo( 
"LoLoAlarmPri",Tg::TagSystems::String,{"MemoryInt","IOInt","MemoryReal","IOReal"
});
setPropertyInfo( 
"LoAlarmState",Tg::TagSystems::String,{"MemoryInt","IOInt","MemoryReal","IOReal"
});
setPropertyInfo( 
"LoAlarmValue",Tg::TagSystems::String,{"MemoryInt","IOInt","MemoryReal","IOReal"
});
setPropertyInfo( 
"LoAlarmPri",Tg::TagSystems::String,{"MemoryInt","IOInt","MemoryReal","IOReal"})
;
setPropertyInfo( 
"HiAlarmState",Tg::TagSystems::String,{"MemoryInt","IOInt","MemoryReal","IOReal"
});
setPropertyInfo( 
"HiAlarmValue",Tg::TagSystems::String,{"MemoryInt","IOInt","MemoryReal","IOReal"
});
setPropertyInfo( 
"HiAlarmPri",Tg::TagSystems::String,{"MemoryInt","IOInt","MemoryReal","IOReal"})
;
setPropertyInfo( 
"HiHiAlarmState",Tg::TagSystems::String,{"MemoryInt","IOInt","MemoryReal",
"IOReal"});
setPropertyInfo( 
"HiHiAlarmValue",Tg::TagSystems::String,{"MemoryInt","IOInt","MemoryReal",
"IOReal"});
setPropertyInfo( 
"HiHiAlarmPri",Tg::TagSystems::String,{"MemoryInt","IOInt","MemoryReal","IOReal"
});
setPropertyInfo( 
"MinorDevAlarmState",Tg::TagSystems::String,{"MemoryInt","IOInt","MemoryReal",
"IOReal"});
setPropertyInfo( 
"MinorDevAlarmValue",Tg::TagSystems::String,{"MemoryInt","IOInt","MemoryReal",
"IOReal"});
setPropertyInfo( 
"MinorDevAlarmPri",Tg::TagSystems::String,{"MemoryInt","IOInt","MemoryReal",
"IOReal"});
setPropertyInfo( 
"MajorDevAlarmState",Tg::TagSystems::String,{"MemoryInt","IOInt","MemoryReal",
"IOReal"});
setPropertyInfo( 
"MajorDevAlarmValue",Tg::TagSystems::String,{"MemoryInt","IOInt","MemoryReal",
"IOReal"});
setPropertyInfo( 
"MajorDevAlarmPri",Tg::TagSystems::String,{"MemoryInt","IOInt","MemoryReal",
"IOReal"});
setPropertyInfo( 
"DevTarget",Tg::TagSystems::String,{"MemoryInt","IOInt","MemoryReal","IOReal"});
setPropertyInfo( 
"ROCAlarmState",Tg::TagSystems::String,{"MemoryInt","IOInt","MemoryReal",
"IOReal"});
setPropertyInfo( 
"ROCAlarmValue",Tg::TagSystems::String,{"MemoryInt","IOInt","MemoryReal",
"IOReal"});
setPropertyInfo( 
"ROCAlarmPri",Tg::TagSystems::String,{"MemoryInt","IOInt","MemoryReal","IOReal"}
);
setPropertyInfo( 
"ROCTimeBase",Tg::TagSystems::String,{"MemoryInt","IOInt","MemoryReal","IOReal"}
);
setPropertyInfo( "MinEU",Tg::TagSystems::Float,{"IOInt","IOReal"});
setPropertyInfo( "MaxEU",Tg::TagSystems::Float,{"IOInt","IOReal"});
setPropertyInfo( "MinRaw",Tg::TagSystems::Float,{"IOInt","IOReal"});
setPropertyInfo( "MaxRaw",Tg::TagSystems::Float,{"IOInt","IOReal"});

setPropertyInfo( "Conversion",Tg::TagSystems::String,{"IOInt","IOReal"});
setPropertyInfo( "MaxLength",
                        Tg::TagSystems::String,
                        {"MemoryMsg","IOMsg"});

setPropertyInfo( "InitialMessage",
                        Tg::TagSystems::String,
                        {"MemoryMsg","IOMsg"});



}
void Tg::TagSystems::InTouch::load ( 
			  const std::istream& strm, 
			  Tg::Project&	project,
			  Tg::FileHandler::Encoding encoding )
{
  NOT_YET_IMPLEMENTED
}
void Tg::TagSystems::InTouch::save ( 
		const Tg::Project& project, 
		std::ostream& strm, 
		Tg::FileHandler::Encoding encoding )
{
  NOT_YET_IMPLEMENTED
}

