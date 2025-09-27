#include <spdlog/spdlog.h>
#include <GLFW/glfw3.h>

int main(int argc, const char** argv)
{
    SPDLOG_INFO("Start Program");

    SPDLOG_INFO("Init glfw");
    if (!glfwInit())
    {
        const char* pDesc = nullptr;
        glfwGetError(&pDesc);
        SPDLOG_ERROR("Failded To Init glfw: {}", pDesc);
        return -1;
    }

    SPDLOG_INFO("Create glfw window");
    GLFWwindow* pWindow = glfwCreateWindow(
        WINDOW_WIDTH, 
        WINDOW_HEIGHT, 
        WINDOW_NAME,
        nullptr,
        nullptr
    );

    if (pWindow == nullptr)
    {
        SPDLOG_ERROR("Failded To create glfw window");
        glfwTerminate();
        return -1;
    }


    SPDLOG_INFO("Start main loop");
    while (!glfwWindowShouldClose(pWindow))
    {
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}