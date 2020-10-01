function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "etc_megaMotoTest"};
	this.sidHashMap["etc_megaMotoTest"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/Constant"] = {sid: "etc_megaMotoTest:1"};
	this.sidHashMap["etc_megaMotoTest:1"] = {rtwname: "<Root>/Constant"};
	this.rtwnameHashMap["<Root>/Scope"] = {sid: "etc_megaMotoTest:2"};
	this.sidHashMap["etc_megaMotoTest:2"] = {rtwname: "<Root>/Scope"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
