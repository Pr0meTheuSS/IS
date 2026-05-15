#include "app.h"
#include "../core/ceasar.h"
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>

using namespace ftxui;

int run_tui() {
  std::string input, output;
  int key = 3;

  auto screen = ScreenInteractive::TerminalOutput();

  auto input_box = Input(&input, "text");
  auto key_box = Input(&input, "key");

  auto btn = Button("Encrypt", [&] { output = core::encrypt(input, key); });

  auto layout = Container::Vertical({input_box, btn});

  auto renderer = Renderer(layout, [&] {
    return vbox(
        {text("ceasar"), input_box->Render(), btn->Render(), text(output)});
  });

  screen.Loop(renderer);
  return 0;
}
