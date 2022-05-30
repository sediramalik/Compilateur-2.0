----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 30.05.2022 20:34:57
-- Design Name: 
-- Module Name: MICROPROCESSOR - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity MICROPROCESSOR is
    Port ( CLK : in STD_LOGIC;
           ADDR : in STD_LOGIC_VECTOR (7 downto 0));
end MICROPROCESSOR;

architecture Behavioral of MICROPROCESSOR is

--COMPONENTS

component INSTRUCTION_BANK is
    Port ( ADDR : in STD_LOGIC_VECTOR (7 downto 0);
           CLK : in STD_LOGIC;
           OUTPUT : out STD_LOGIC_VECTOR (31 downto 0)
 );
end component;

component PIPELINE is
    Port ( CLK : in STD_LOGIC;
           OP_IN : in STD_LOGIC_VECTOR (7 downto 0);
           A_IN : in STD_LOGIC_VECTOR (7 downto 0);
           B_IN : in STD_LOGIC_VECTOR (7 downto 0);
           C_IN : in STD_LOGIC_VECTOR (7 downto 0);
           OP_OUT : out STD_LOGIC_VECTOR (7 downto 0);
           A_OUT : out STD_LOGIC_VECTOR (7 downto 0);
           B_OUT : out STD_LOGIC_VECTOR (7 downto 0);
           C_OUT : out STD_LOGIC_VECTOR (7 downto 0));
end component;

component REGISTER_FILE is
    Port ( aA : in STD_LOGIC_VECTOR (3 downto 0);
           aB : in STD_LOGIC_VECTOR (3 downto 0);
           aW : in STD_LOGIC_VECTOR (3 downto 0);
           W : in STD_LOGIC;
           DATA : in STD_LOGIC_VECTOR (7 downto 0);
           RST : in STD_LOGIC; 
           CLK : in STD_LOGIC;
           QA : out STD_LOGIC_VECTOR (7 downto 0);
           QB : out STD_LOGIC_VECTOR (7 downto 0));
end component;

component UAL is
    Port ( A : in STD_LOGIC_VECTOR (7 downto 0); 
           B : in STD_LOGIC_VECTOR (7 downto 0);
           CTRL_ALU : in STD_LOGIC_VECTOR (2 downto 0);
           N : out STD_LOGIC; 
           O : out STD_LOGIC; 
           Z : out STD_LOGIC; 
           C : out STD_LOGIC; 
           S : out STD_LOGIC_VECTOR (7 downto 0));
end component;

component MEMORY_BANK is
    Port ( ADDR : in STD_LOGIC_VECTOR (7 downto 0);
           INPUT : in STD_LOGIC_VECTOR (7 downto 0);
           RW : in STD_LOGIC;
           RST : in STD_LOGIC;
           CLK : in STD_LOGIC;
           OUTPUT : out STD_LOGIC_VECTOR (7 downto 0));
end component;

--SIGNALS

--PIPELINE OUTPUTS
signal LIDI_OP_OUT : STD_LOGIC_VECTOR (7 downto 0);
signal LIDI_A_OUT :  STD_LOGIC_VECTOR (7 downto 0);
signal LIDI_B_OUT :  STD_LOGIC_VECTOR (7 downto 0);
signal LIDI_C_OUT :  STD_LOGIC_VECTOR (7 downto 0);

signal DIEX_OP_OUT : STD_LOGIC_VECTOR (7 downto 0);
signal DIEX_A_OUT :  STD_LOGIC_VECTOR (7 downto 0);
signal DIEX_B_OUT :  STD_LOGIC_VECTOR (7 downto 0);
signal DIEX_C_OUT :  STD_LOGIC_VECTOR (7 downto 0);

signal EXMEM_OP_OUT : STD_LOGIC_VECTOR (7 downto 0);
signal EXMEM_A_OUT :  STD_LOGIC_VECTOR (7 downto 0);
signal EXMEM_B_OUT :  STD_LOGIC_VECTOR (7 downto 0);

signal MEMRE_OP_OUT : STD_LOGIC_VECTOR (7 downto 0);
signal MEMRE_A_OUT :  STD_LOGIC_VECTOR (7 downto 0);
signal MEMRE_B_OUT :  STD_LOGIC_VECTOR (7 downto 0);
signal MEMRE_C_OUT :  STD_LOGIC_VECTOR (7 downto 0);

--INSTRUCTION BANK OUTPUT
signal INSTR_BANK_OUT : std_logic_vector(31 downto 0);


--REGISTER FILE OUTPUTS
signal REG_FILE_QA_OUT : STD_LOGIC_VECTOR (7 downto 0);
signal REG_FILE_QB_OUT : STD_LOGIC_VECTOR (7 downto 0);

--UAL OUTPUT
signal UAL_OUT : STD_LOGIC_VECTOR (7 downto 0);

--MEMORY BANK OUTPUTS
signal MEM_BANK_OUT : STD_LOGIC_VECTOR (7 downto 0);

--LC
    --LC UAL OUTPUT
signal LC_UAL_OUT : STD_LOGIC_VECTOR (2 downto 0);
    --LC MEMORY BANK OUTPUTS
signal LC_MEM_BANK : STD_LOGIC;
    --LC FINAL_OUTPUT
signal LC_FINAL_OUT : STD_LOGIC;

--MUX
    --MUX REGISTER FILE OUTPUT
signal MUX_REG_FILE_OUT : STD_LOGIC_VECTOR (7 downto 0);
    --MUX_UAL OUTPUT
signal MUX_UAL_OUT : STD_LOGIC_VECTOR (7 downto 0);
    --MUX MEMORY BANK
signal MUX_MEM_BANK_OUT : STD_LOGIC_VECTOR (7 downto 0);
signal MUX_OUT_MEM_BANK_IN : STD_LOGIC_VECTOR (7 downto 0);

--PORT MAPS
begin

--INSTRUCTION BANK
INSTRUCTION_BANK_MAP: INSTRUCTION_BANK
port map(           
CLK => CLK,
ADDR => ADDR,
OUTPUT => INSTR_BANK_OUT
);

--INSTRUCTION_BANK => LI/DI
LIDI_MAP: PIPELINE
port map(           
CLK => CLK,
OP_IN => MEM_BANK_OUT(31 downto 24), --FIRST 8 BITS GO TO OP
A_IN => MEM_BANK_OUT(23 downto 16), --SECOND 8 BITS GO TO A
B_IN => MEM_BANK_OUT(15 downto 8), --THIRD 8 BITS GO TO B
C_IN => MEM_BANK_OUT(7 downto 0), --LAST 8 BITS GO TO C
OP_OUT => LIDI_OP_OUT,
A_OUT => LIDI_A_OUT,
B_OUT => LIDI_B_OUT,
C_OUT => LIDI_C_OUT
);

end Behavioral;
