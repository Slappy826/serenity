/*
 * Copyright (c) 2020, Andreas Kling <kling@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibGUI/Dialog.h>

namespace GUI {

class EmojiInputDialog final : public Dialog {
    C_OBJECT(EmojiInputDialog);

    struct Emoji {
        u32 code_point { 0 };
        Optional<String> name;
        RefPtr<Button> button;
    };

public:
    String const& selected_emoji_text() const { return m_selected_emoji_text; }

private:
    virtual void event(Core::Event&) override;
    explicit EmojiInputDialog(Window* parent_window);

    Vector<Emoji> supported_emoji();
    void update_displayed_emoji();

    RefPtr<TextBox> m_search_box;
    RefPtr<Widget> m_emojis_widget;
    Vector<Emoji> m_emojis;
    String m_selected_emoji_text;
};

}
