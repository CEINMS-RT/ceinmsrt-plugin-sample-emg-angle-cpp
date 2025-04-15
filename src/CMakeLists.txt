ADD_LIBRARY( SampleEMGAndAnglePlugin SHARED SampleEMGAndAnglePlugin.cpp)


TARGET_LINK_LIBRARIES( SampleEMGAndAnglePlugin
	FileIO
	XMLIKIDInterpreter
	XMLExecutionInterpreter
	${Boost_LIBRARIES}
	XercesC::XercesC
	FileLogger
)