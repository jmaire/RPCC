#include "Alignment.h"

Alignment::Alignment()
: Alignment(EthicalAlignment::NEUTRAL, MoralAlignment::NEUTRAL)
{}

Alignment::Alignment(EthicalAlignment eA, MoralAlignment mA)
: m_ethicalAlignment(eA)
, m_moralAlignment(mA)
{}

/*virtual*/ Alignment::~Alignment()
{}
