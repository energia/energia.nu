import glob, os
os.chdir(".")
for file in glob.glob("*.adoc"):


	data = ""
	with open(file, 'r') as myfile:
		data = myfile.read()
		data = data.replace("#### Description","=== Description ===")
		data = data.replace("#### Syntax","=== Syntax ===")
		data = data.replace("#### Example","=== Example ===")
		data = data.replace("#### Returns","=== Returns ===")
		data = data.replace("#### Parameters","=== Parameters ===")
			
		data = data.replace("<span class=\"wikiword\">","")
		data = data.replace("</span>","")
		data = data.replace("[Reference Home](http://energia.nu/reference/ \"Reference\"){.wikilink} ||","")
		data = data.replace("[WiFi Library](http://energia.nu/reference/wifi/ \"WiFi\")","")
		data = data.replace("--------","")
		data = data.replace("------------------------------------------","")
		data = data.replace("","")
		data = data.replace("[Stream](http://energia.nu/reference/stream/ \"Stream\"){.wikilink}","http://energia.nu/reference/stream/[Stream]")

		


	f = open(file, "w")
	data = data.rstrip()
	f.write(data)