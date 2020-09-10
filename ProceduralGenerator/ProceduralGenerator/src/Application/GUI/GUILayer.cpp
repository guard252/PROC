#include "pch.h"
#include "GUILayer.h"
#include "Application/Application.h"

#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_glfw.h"



GUILayer::GUILayer()
{
	
}


void GUILayer::OnEvent(Event& e)
{
		ImGuiIO& io = ImGui::GetIO();
		e.m_is_handled |= e.IsInCategory(EventCategory::EventCategoryMouse) & io.WantCaptureMouse;
		e.m_is_handled |= e.IsInCategory(EventCategory::EventCategoryKeyboard) & io.WantCaptureKeyboard;	
}

void GUILayer::OnGUIRender()
{
	ImGui::ShowDemoWindow();
}

void GUILayer::Begin()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void GUILayer::End()
{
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void GUILayer::OnUpdate()
{
	Begin();
	
	OnGUIRender();

	End();
}

void GUILayer::OnAttach()
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();


	ImGui::StyleColorsDark();
	

	ImGuiStyle& style = ImGui::GetStyle();
	if (io.ConfigFlags)
	{
		style.WindowRounding = 0.0f;
		style.Colors[ImGuiCol_WindowBg].w = 1.0f;
	}


	ImGui_ImplGlfw_InitForOpenGL(Application::Get().GetWindow()->GetRawWindow(), true);
	ImGui_ImplOpenGL3_Init("#version 440");
}

void GUILayer::OnDetach()
{
}
