#pragma once
#include "../ui_widget.h"
#include "halley/core/graphics/sprite/sprite.h"

namespace Halley {
	class UIStyle;
	class AudioClip;

	class UIClickable : public UIWidget {
	public:
		explicit UIClickable(String id, Vector2f minSize, Maybe<UISizer> sizer = {}, Vector4f innerBorder = {});

		bool isFocusable() const override;
		bool isFocusLocked() const override;

		void pressMouse(int button) override;
		void releaseMouse(int button) override;

		void onClick(UIEventCallback callback);
		virtual void onClicked() = 0;

	protected:
		enum class State {
			Up,
			Down,
			Hover
		};

		virtual void doSetState(State state) = 0;
		bool updateButton();

	private:
		State curState = State::Up;
		bool held = false;

		bool setState(State state);
	};

	class UIButton : public UIClickable {
	public:
		explicit UIButton(String id, std::shared_ptr<UIStyle> style);

		void draw(UIPainter& painter) const override;
		void update(Time t, bool moved) override;
		void onClicked() override;

	protected:
		void doSetState(State state) override;

	private:
		Sprite sprite;
		std::shared_ptr<UIStyle> style;
	};
}