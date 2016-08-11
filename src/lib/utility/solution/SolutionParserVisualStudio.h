#ifndef SOLUTION_PARSER_VISUAL_STUDIO_H
#define SOLUTION_PARSER_VISUAL_STUDIO_H

#include "ISolutionParser.h"

#include "tinyxml/tinyxml.h"

class SolutionParserVisualStudio : public ISolutionParser
{
public:
	SolutionParserVisualStudio();
	virtual ~SolutionParserVisualStudio();

	virtual std::string getToolID() const;

	virtual std::string getSolutionName();

	virtual std::vector<std::string> getProjects();
	virtual std::vector<std::string> getProjectFiles();
	virtual std::vector<std::string> getProjectItems();
	virtual std::vector<std::string> getIncludePaths();
	virtual std::vector<std::string> getCompileFlags();

	virtual std::shared_ptr<ProjectSettings> getProjectSettings(const std::string& solutionFilePath);

	virtual std::string getIdeName() const;
	virtual std::string getButtonText() const;
	virtual std::string getDescription() const;
	virtual std::string getIconPath() const;
	virtual std::string getFileExtension() const;

	std::vector<std::string> getProjectItemsNonCanonical(); // for testing purposes, paths returned are non canonical, don't use if you don't know what that means
	std::vector<std::string> getIncludePathsNonCanonical(); // for testing purposes, paths returned are non canonical, don't use if you don't know what that means

private:
	std::vector<std::string> findProjectItems();
	std::vector<std::string> findIncludePaths();

	std::vector<std::string> getProjectBlocks(const std::string& solution) const;
	std::string getProjectFilePath(const std::string& projectBlock) const;

	std::vector<std::string> seperateIncludePaths(const std::vector<std::string>& includePaths) const;
	std::vector<std::string> seperateIncludePaths(const std::string& includePaths) const;

	std::vector<std::string> seperateCompilerFlags(const std::vector<std::string>& compilerFlags) const;
	std::vector<std::string> seperateCompilerFlags(const std::string& compilerFlags) const;

	void setProjectMacros(const std::string& projectName);

	std::vector<std::string> m_compatibilityFlags;
};

// list of possible vs ide macros
// source: https://msdn.microsoft.com/en-us/library/c02as0cs.aspx
/*
"RemoteMachine",
"Configuration",
"Platform",
"ParentName",
"RootNameSpace",
"IntDir",
"OutDir",
"DevEnvDir",
"InputDir",
"InputPath",
"InputName",
"InputFileName",
"InputExt",
"ProjectDir",
"ProjectPath",
"ProjectName",
"ProjectFileName",
"ProjectExt",
"SolutionDir",
"SolutionPath",
"SolutionName",
"SolutionExt",
"TargetDir",
"TargetPath",
"TargetName",
"TargetFileName",
"VSInstallDir",
"VCInstallDir",
"FrameworkDir",
"FrameworkVersion",
"FrameworkSDKDir",
"WebDeployPath",
"WebDeployRoot",
"SafeParentName",
"SafeInputName",
"SafeRootNamespace",
"FxCopDir"
*/

#endif // SOLUTION_PARSER_VISUAL_STUDIO_H
