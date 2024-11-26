//Citation and Sources...
//Final Project Milestone 2
//Module: Time
//Filename: Time.h
//Version 1.0
//Author   Jenny Zhang
//Revision History
//-----------------------------------------------------------
//Date      2024/03/23
//2023/03/20  Preliminary release
//2024/03/22  Debugged DMA
//-----------------------------------------------------------
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.

namespace seneca {
	class IOAble {
	public:
		virtual std::ostream& write(std::ostream& out) const = 0;
		virtual std::istream& read(std::istream& in) = 0;
		virtual ~IOAble() {};

		friend std::ostream& operator<<(std::ostream& out, const IOAble& io) {
			return io.write(out);
		}

		friend std::istream& operator>>(std::istream& in, IOAble& io) {
			return io.read(in);
		}
	};
}