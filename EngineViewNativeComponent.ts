import type { HostComponent, ViewProps } from 'react-native';
import codegenNativeComponent from 'react-native/Libraries/Utilities/codegenNativeComponent';
import type { DirectEventHandler, Double, Int32 } from 'react-native/Libraries/Types/CodegenTypes';

type SnapshotEvent = { event: Int32 };

export interface NativeEngineViewProps extends ViewProps {
  isTransparent: boolean;
  antiAliasing: Double;
  androidView: string;
  onSnapshotDataReturned?: DirectEventHandler<SnapshotEvent>;
}

export default codegenNativeComponent<NativeEngineViewProps>('EngineView') as HostComponent<NativeEngineViewProps>;
