#include "GLSLProgram.h"
#include <vector>
#include <fstream>
GLSLProgram::GLSLProgram() : numAttributes(0), programID(0),
    vertexShaderID(0), fragmentShaderID(0){

}

GLSLProgram::~GLSLProgram(){}
void GLSLProgram :: compileShaders(const std::string& vertexShaderIDFilePath,
                                   const std::string& fragmentShaderIDFilePath){
    programID = glCreateProgram();
    vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    if(vertexShaderID == 0){
        printError("Vertex shader failed to be created!");
    }

    fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    if(fragmentShaderID == 0){
        printError("Fragment shader failed to be created!");
    }

    compileShader(vertexShaderIDFilePath, vertexShaderID);
    compileShader(fragmentShaderIDFilePath, fragmentShaderID);


}

void GLSLProgram :: compileShader(const std::string filePath, GLuint id){
    std::ifstream ShaderFile(filePath);
    if(ShaderFile.fail()){
        printError("Failed to open " + id + filePath);
    }

    std::string fileContents = "";
    std::string line;

    while(std::getline(ShaderFile, line)){
        fileContents += line + "\n";
    }

    ShaderFile.close();

    const char* contents = fileContents.c_str();

    glShaderSource(id, 1, &contents, nullptr);

    glCompileShader(id);

    GLint success = 0;

    glGetShaderiv(id, GL_COMPILE_STATUS, &success);

    if(success == GL_FALSE){
        GLint maxLength = 0;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);
        std::vector<char> errorlog(maxLength);
        glGetShaderInfoLog(id, maxLength, &maxLength, &errorlog[0]);

        glDeleteShader(id);

        //Use the infoLog as you see fit.

        //In this simple program, we'll just leave
        printError("Shader " + filePath + " failed to compile");
        std::printf("%s\n", &(errorlog[0]));
        return;

    }

}

void GLSLProgram :: linkShaders(){
    //Vertex and fragment shaders are successfully compiled.
    //Now time to link them together into a programID.
    //Get a programID object.

    //Attach our shaders to our programID
    glAttachShader(programID, vertexShaderID);
    glAttachShader(programID, fragmentShaderID);

    //Link our programID
    glLinkProgram(programID);

    //Note the different functions here: glGetProgram* instead of glGetShader*.
    GLint isLinked = 0;
    glGetProgramiv(programID, GL_LINK_STATUS, (int *)&isLinked);
    if(isLinked == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &maxLength);

        //The maxLength includes the NULL character
        std::vector<char> errorlog(maxLength);
        glGetProgramInfoLog(programID, maxLength, &maxLength, &errorlog[0]);

        //We don't need the programID anymore.
        glDeleteProgram(programID);
        //Don't leak shaders either.
        glDeleteShader(vertexShaderID);
        glDeleteShader(fragmentShaderID);

        std::printf("%s\n", &(errorlog[0]));
        printError("Shaders failed to link");


        //Use the infoLog as you see fit.

        //In this simple programID, we'll just leave
        return;
    }
    //Always detach shaders after a successful link.
    glDetachShader(programID, vertexShaderID);
    glDetachShader(programID, fragmentShaderID);
    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);
}


void GLSLProgram::addAttribute(const std::string & attributeName){
    glBindAttribLocation(programID, numAttributes++, attributeName.c_str());

}

GLint GLSLProgram::getUniformLocation(const std::string& uniformName){
    GLint location = glGetUniformLocation(programID, uniformName.c_str());
    if(location == GL_INVALID_INDEX){
        printError("Uniform " + uniformName + "not found");
    }
    return location;
}

void GLSLProgram::use(){
   glUseProgram(programID);
   for(int i = 0; i < numAttributes; ++i){
       glEnableVertexAttribArray(i);
   }
}

void GLSLProgram::unuse(){
    glUseProgram(0);
    for(int i = 0; i < numAttributes; ++i){
        glDisableVertexAttribArray(i);
    }
}

