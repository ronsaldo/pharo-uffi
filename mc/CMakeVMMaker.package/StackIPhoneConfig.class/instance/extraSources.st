source files
extraSources
	" mac VM using some unix sources "
	
	^'${buildDir}/', self prefixHeaderFileName, ' 
${resources} ', 
'${buildDir}/', self prefixHeaderFileName, ' 
${resourcesLocaleEnglish} 
${platformsDir}/unix/vm/sqUnixHeartbeat.c  
${platformsDir}/unix/vm/sqUnixThreads.c 
${platformsDir}/unix/vm/aio.c
'