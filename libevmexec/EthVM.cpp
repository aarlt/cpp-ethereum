#include "EthVM.h"

#include <libdevcore/CommonIO.h>
#include <libdevcore/SHA3.h>
#include <libethcore/SealEngine.h>
#include <libethereum/Block.h>
#include <libethereum/Executive.h>
#include <libethereum/ChainParams.h>
#include <libethereum/LastBlockHashesFace.h>
#include <libethashseal/GenesisInfo.h>
#include <libethashseal/Ethash.h>
#include <libevm/VM.h>
#include <libevm/VMFactory.h>
#include <boost/algorithm/string.hpp>
#include <boost/program_options.hpp>
#include <boost/program_options/options_description.hpp>
#include <fstream>
#include <iostream>
#include <ctime>

using namespace std;
using namespace dev;
using namespace eth;

namespace
{
int64_t maxBlockGasLimit()
{
    static int64_t limit = ChainParams(genesisInfo(Network::MainNetwork)).maxGasLimit.convert_to<int64_t>();
    return limit;
}
}

EthVM::EthVM() 
{
    Network networkName = Network::MainNetworkTest;
    (void)networkName;
    BlockHeader blockHeader; // fake block to be executed in
    blockHeader.setGasLimit(maxBlockGasLimit());
    blockHeader.setTimestamp(0);

    Ethash::init();
    NoProof::init();
}
