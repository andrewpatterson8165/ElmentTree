#include <windows.h>
#include <stdexcept>

class Window {
public:
    Window(const char* className, const char* title, int x, int y, int width, int height) {
        WNDCLASS wc = {};
        wc.lpfnWndProc = &Window::WndProc;
        wc.hInstance = GetModuleHandle(nullptr);
        wc.lpszClassName = className;
        
        if (!RegisterClass(&wc)) {
            throw std::runtime_error("Failed to register window class.");
        }

        hwnd_ = CreateWindowEx(
            0, className, title, WS_OVERLAPPEDWINDOW,
            x, y, width, height, nullptr, nullptr, GetModuleHandle(nullptr), this
        );

        if (!hwnd_) {
            throw std::runtime_error("Failed to create window.");
        }
        
        SetWindowLongPtr(hwnd_, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));
    }

    ~Window() {
        DestroyWindow(hwnd_);
    }

    void show(int cmdShow) {
        ShowWindow(hwnd_, cmdShow);
    }

    void update() {
        UpdateWindow(hwnd_);
    }

    HWND handle() const {
        return hwnd_;
    }

    static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        if (msg == WM_CREATE) {
            CREATESTRUCT* cs = reinterpret_cast<CREATESTRUCT*>(lParam);
            Window* window = static_cast<Window*>(cs->lpCreateParams);
            SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(window));
            return 0;
        }

        Window* window = reinterpret_cast<Window*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
        if (window) {
            return window->processMessage(hwnd, msg, wParam, lParam);
        }

        return DefWindowProc(hwnd, msg, wParam, lParam);
    }

protected:
    virtual LRESULT processMessage(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        switch (msg) {
            case WM_DESTROY:
                PostQuitMessage(0);
                return 0;
            default:
                return DefWindowProc(hwnd, msg, wParam, lParam);
        }
    }

private:
    HWND hwnd_;
};
